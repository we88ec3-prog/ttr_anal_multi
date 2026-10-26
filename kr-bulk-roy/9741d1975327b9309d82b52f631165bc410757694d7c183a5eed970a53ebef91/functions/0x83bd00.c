
void FUN_0083bd00(void)

{
  uint uVar1;
  int *in_ECX;
  uint uVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = (**(code **)(*in_ECX + 0xac))();
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      local_c = 0;
      local_8 = 0;
      (**(code **)(*in_ECX + 0xb0))(uVar2,&local_c,&local_8);
      (**(code **)(*in_ECX + 0xa8))(&local_8);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

