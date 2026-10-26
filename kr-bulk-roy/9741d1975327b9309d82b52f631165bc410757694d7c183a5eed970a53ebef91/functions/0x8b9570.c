
void FUN_008b9570(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = *(uint *)(param_1 + 4);
    uVar1 = uVar2 + *(short *)(param_1 + 2) * 8;
    for (; uVar2 < uVar1; uVar2 = uVar2 + 8) {
      FUN_008b9510(uVar2,param_2);
    }
  }
  return;
}

