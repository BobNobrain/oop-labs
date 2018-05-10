(((([
    x = @ this => 0,
    y = @ this => 0,
    move_x = @ this => \ dx => this.x := this.x + dx,
    move_y = @ this => \ dy => this.y := this.y + dy,
    set_x = @ this => \ nx => this.x := nx,
    set_y = @ this => \ ny => this.y := ny
]
.x := 5)
.y := 3)
.move_x 100)
.move_y 100)
.x
