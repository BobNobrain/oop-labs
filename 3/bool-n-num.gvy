([
    false = @ that => [
        arg1 = @ this => this.arg1,
        arg2 = @ this => this.arg2,
        result = @ this => this.arg2
    ],
    true = @ that => [
        arg1 = @ this => this.arg1,
        arg2 = @ this => this.arg2,
        result = @ this => this.arg1
    ],
    zero = @ that => [
        iszero = @ this => that.true,
        succ = @ this => ((this.iszero := that.false).pred := this).n := this.n + 1,
        pred = @ this => this,
        n = @ this => 0
    ]
]).zero.succ.succ.n
