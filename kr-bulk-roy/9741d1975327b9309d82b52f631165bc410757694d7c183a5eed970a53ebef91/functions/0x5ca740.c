
void FUN_005ca740(void)

{
  int iVar1;
  int *in_ECX;
  int local_c;
  int local_8;
  
  if ((char)in_ECX[0x26] != '\0') {
    if ((int *)in_ECX[2] != (int *)0x0) {
      (**(code **)(*(int *)in_ECX[2] + 8))();
      in_ECX[2] = 0;
    }
    in_ECX[0x16] = 0;
    in_ECX[0x17] = 0;
    *(undefined1 *)(in_ECX + 0x26) = 0;
  }
  iVar1 = in_ECX[0x28];
  if (iVar1 != 0) {
    local_8 = in_ECX[3];
    FUN_0082ef00(&local_8);
    if (local_c != *(int *)(iVar1 + 0xc)) {
      FUN_007b6890(iVar1 + 8,&local_c,local_c);
    }
    (**(code **)(*in_ECX + 0x1c))(1);
  }
  return;
}

