# single-register-machine
Assume a machine that has a single register and six instructions.<br>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>LD A</b> which places the operand <b>A</b> into the register.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>ST A</b> which places the contents of the register into the variable <b>A</b>.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>AD A</b> which adds the contents of variable <b>A</b> to the register.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>SB A</b> which subtracts the contents of the variable <b>A</b> from the register.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>ML A</b> which multiplies the contents of the register by the variable <b>A</b>.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>DV A</b> which divides the contents of the register by the variable <b>A</b>.<br>

Write C a program that accepts a postfix expression containing single-letter operands and
the operators + , - , * , and / and which prints a sequence of instructions to evaluate the

expression and leave the result in the register.<br>

Use variables of the form *TEMPn* as temporary variables.<br>

For example, the postfix expression ABC*+DE-/ should yield the printout.<br>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b>LD B<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ML C<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ST TEMP1<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;LD A<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;AD TEMP1<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ST TEMP2<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;LD D<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SB E<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ST TEMP3LD TEMP2<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;DV TEMP3<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ST TEMP4<br></b>