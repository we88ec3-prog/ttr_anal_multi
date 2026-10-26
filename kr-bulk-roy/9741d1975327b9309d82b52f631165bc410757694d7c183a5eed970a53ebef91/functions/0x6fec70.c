
void FUN_006fec70(int param_1,int *param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  uVar2 = (param_3 >> 5) + 1;
  uVar4 = param_3;
  for (uVar3 = param_3; uVar2 <= uVar3; uVar3 = uVar3 - uVar2) {
    uVar4 = uVar4 ^ (uint)*(byte *)((int)param_2 + (uVar3 - 1)) + uVar4 * 0x20 + (uVar4 >> 2);
  }
  puVar1 = *(undefined4 **)
            (**(int **)(param_1 + 0x10) + ((*(int **)(param_1 + 0x10))[2] - 1U & uVar4) * 4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
      FUN_006febc0(param_1,param_2,uVar4);
      return;
    }
    if (puVar1[3] == param_3) {
      piVar5 = puVar1 + 4;
      piVar6 = param_2;
      for (uVar3 = param_3; 3 < uVar3; uVar3 = uVar3 - 4) {
        if (*piVar6 != *piVar5) goto LAB_006fed14;
        piVar5 = piVar5 + 1;
        piVar6 = piVar6 + 1;
      }
      if ((uVar3 == 0) ||
         (((char)*piVar5 == (char)*piVar6 &&
          ((uVar3 < 2 ||
           ((*(char *)((int)piVar5 + 1) == *(char *)((int)piVar6 + 1) &&
            ((uVar3 < 3 || (*(char *)((int)piVar5 + 2) == *(char *)((int)piVar6 + 2))))))))))) {
        if ((*(byte *)((int)puVar1 + 5) & 3 & ~*(byte *)(*(int *)(param_1 + 0x10) + 0x14)) == 0) {
          return;
        }
        *(byte *)((int)puVar1 + 5) = *(byte *)((int)puVar1 + 5) ^ 3;
        return;
      }
    }
LAB_006fed14:
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

