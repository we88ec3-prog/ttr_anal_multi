
int FUN_008e9b40(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1 << 0x10 | param_1[1];
  uVar2 = *param_2 << 0x10 | param_2[1];
  if (uVar2 < uVar1) {
    return 1;
  }
  return -(uint)(uVar1 < uVar2);
}

