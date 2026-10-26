
uint FUN_008b9a40(int *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint3 in_ECX;
  undefined4 uStack_8;
  
  *param_2 = 0;
  uStack_8 = (uint)in_ECX;
  if ((code *)param_1[5] == (code *)0x0) {
    uVar2 = param_1[2];
    if (uVar2 < (uint)param_1[1]) {
      uVar1 = *(undefined1 *)(uVar2 + *param_1);
      param_1[2] = param_1[2] + 1;
      return CONCAT31((int3)(uVar2 >> 8),uVar1);
    }
  }
  else {
    uVar2 = (*(code *)param_1[5])(param_1,param_1[2],(int)&uStack_8 + 3,1);
    if (uVar2 == 1) {
      param_1[2] = param_1[2] + 1;
      return uStack_8 >> 0x18;
    }
  }
  *param_2 = 0x55;
  return uVar2 & 0xffffff00;
}

