type a = {};
type b = {};

function f<T>() {
    return function <U>() {
        return 1 as U;
    }
}

const x = f<number>;