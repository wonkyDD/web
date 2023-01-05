const path = require('path');

module.exports = {
    entry: {
        client: './ThreeJS/src/client/client.ts',
        testbed: './ThreeJS/src/client/testbed.ts',
    },
    module: {
        rules: [
            {
                test: /\.tsx?$/,
                use: 'ts-loader',
                exclude: /node_modules/,
            },
        ],
    },
    resolve: {
        alias: {
            three: path.resolve('./node_modules/three'),
        },
        extensions: ['.tsx', '.ts', '.js'],
    },
    output: {
        filename: '[name].js',
        path: path.resolve(__dirname, '../../dist/client'),
    },
};
