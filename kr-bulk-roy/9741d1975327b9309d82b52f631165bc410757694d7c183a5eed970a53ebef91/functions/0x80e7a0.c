
void FUN_0080e7a0(void)

{
  int *in_ECX;
  
  if (in_ECX[5] != 0) {
    (**(code **)(*in_ECX + 0x2c))();
    if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[5])(1);
    }
    in_ECX[5] = 0;
  }
  return;
}

