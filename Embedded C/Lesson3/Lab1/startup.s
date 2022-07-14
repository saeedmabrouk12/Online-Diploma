
@reset section is symbol to make it symbol(to make it viewed by all files)
.global reset

reset:
	ldr sp, =stack_top  @load data to register
	bl main				@brach label 
						@we can replace main by any name

stop: b stop	 		@branch
