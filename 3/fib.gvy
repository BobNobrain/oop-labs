([
    false = @ that =>
    [
        then = @ this => this.then,
        else = @ this => this.else,
        result = @ this => this.else
    ],
    true = @ that =>
    [
        then = @ this => this.then,
        else = @ this => this.else,
        result = @ this => this.then
    ],
    zero = @ that =>
    [
        iszero = @ this => that.true,
        succ = @ this => ((this.iszero := that.false).pred := this).n := this.n + 1,
        pred = @ this => this,
        n = @ this => 0,
        fib = @ this => (
            // if this == 0 then 0 else
            (this.iszero.then := 0).else := (
                // if this == 1 then 1 else
                ((this.pred.iszero.then := 1).else := (
                    // fib(this - 1) + fib(this - 2)
                    (this.pred.fib) + (this.pred.pred.fib)
                )).result
            )
        ).result
    ]
]).zero.succ.succ.succ.succ.fib
