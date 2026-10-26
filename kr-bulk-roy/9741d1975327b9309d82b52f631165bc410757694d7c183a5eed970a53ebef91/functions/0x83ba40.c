
void FUN_0083ba40(void)

{
  int *piVar1;
  uint uVar2;
  int *in_ECX;
  uint uVar3;
  undefined1 local_c [4];
  undefined4 local_8;
  
  uVar2 = (**(code **)(*in_ECX + 0x88))();
  uVar3 = 0;
  if (uVar2 != 0) {
    do {
      local_8 = 0;
      (**(code **)(*in_ECX + 0x8c))(uVar3,local_c,&local_8);
      (**(code **)(*in_ECX + 0x84))(&local_8);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  piVar1 = (int *)in_ECX[0xfc];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0xfc] = 0;
  }
  D3DXCreateEffectPool(in_ECX + 0xfc);
  return;
}

