
int FUN_008cfb50(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  uVar3 = uVar1 & 0x7fffffff;
  uVar4 = uVar2 & 0x7fffffff;
  if (uVar3 == uVar4) {
    bVar5 = uVar1 < uVar2;
    if (uVar1 <= uVar2) {
LAB_008cfb81:
      return -(uint)bVar5;
    }
  }
  else if (uVar3 <= uVar4) {
    bVar5 = uVar3 < uVar4;
    goto LAB_008cfb81;
  }
  return 1;
}

