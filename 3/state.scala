(((([
    state = @ this => this,
    x = @ this => 0,
    backup = @ this => this.state := this,
    restore = @ this => this.state
]
.x := 2)
.backup)
.x := 1)
.restore)
.x
