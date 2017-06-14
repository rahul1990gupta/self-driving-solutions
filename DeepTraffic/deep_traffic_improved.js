
//<![CDATA[

// a few things don't have var in front of them - they update already existing variables the game needs

// More data gives the system more options to train on.

lanesSide = 3;
patchesAhead = 50;
patchesBehind = 10;
trainIterations = 500000;

var num_inputs = (lanesSide * 2 + 1) * (patchesAhead + patchesBehind);
var num_actions = 5;
var temporal_window = 0;
var network_size = num_inputs * temporal_window + num_actions * temporal_window + num_inputs;

var layer_defs = [];
layer_defs.push({
    type: 'input',
    out_sx: 1,
    out_sy: 1,
    out_depth: network_size
});
// More layers allows network to learn complex functions and learn behaviour outside
// trvial behaviour
layer_defs.push({
    type: 'fc',
    num_neurons: 36,
    activation: 'tanh'
});

// Sigmoid: gradient becomes smaller, as we increase the value of f(x) = 1/(1+ e^-x)
// Tanh: f(x) = (e^x - e^-x)/(e^x + e^-x).
// Relu : max(0, x): reduced likelihood of gradient to vanish. constant gradient result in faster learning.
// other benefit: Sparsity. Generalizes better. makes it possible to stack more layers without worrying about over-fitting
// choose tanh to converge faster.

layer_defs.push({
    type: 'fc',
    num_neurons: 24,
    activation: 'tanh'
});
layer_defs.push({
    type: 'fc',
    num_neurons: 24,
    activation: 'tanh'
});
layer_defs.push({
    type: 'fc',
    num_neurons: 24,
    activation: 'tanh'
});
layer_defs.push({
    type: 'regression',
    num_neurons: num_actions
});

var tdtrainer_options = {
    learning_rate: 0.001,
    momentum: 0.0,
    batch_size: 128,
    l2_decay: 0.01
};
/*
Gamma
Algorithm tries to optimize cumulative discounted rewards
Higher the value of gamma, more it will focus on future.
typically people use 0.9. we use 0.98 here.
r1 + gamma*r2 + gamma^2*r3 + gamma^3*r4 ...

*/
var opt = {};
opt.temporal_window = temporal_window;
opt.experience_size = 100000;
opt.start_learn_threshold = 50000;
opt.gamma = 0.98;
opt.learning_steps_total = 500000;
opt.learning_steps_burnin = 1000;
opt.epsilon_min = 0.0;
opt.epsilon_test_time = 0.0;
opt.layer_defs = layer_defs;
opt.tdtrainer_options = tdtrainer_options;

brain = new deepqlearn.Brain(num_inputs, num_actions, opt);

learn = function (state, lastReward) {
    brain.backward(lastReward);
    var action = brain.forward(state);

    draw_net();
    draw_stats();

    return action;
}

//]]>