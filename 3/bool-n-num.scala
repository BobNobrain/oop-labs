([
    false = @ that => [
        then = @ this => this.then,
        else = @ this => this.else,
        result = @ this => this.else
    ],
    true = @ that => [
        then = @ this => this.then,
        else = @ this => this.else,
        result = @ this => this.then
    ],
    zero = @ that => [
        iszero = @ this => that.true,
        succ = @ this => ((this.iszero := that.false).pred := this).n := this.n + 1,
        pred = @ this => this,
        n = @ this => 0,

        // (this == 0? z : f(z-1))
        // test task
        ifzero = @ this => \ z => \ f => (
            (this.iszero.then := z).else := (f (z.pred))
        ).result
    ],

    // used to test what ifzero does
    test = @ that => [
        one = @ this => that.zero.succ,
        two = @ this => that.zero.succ.succ,
        test0 = @ this => (that.zero.ifzero (this.two) (\x => x.pred)),
        test1 = @ this => (this.two.ifzero (this.two) (\x => x.pred))
    ]
]).test.test0.n
