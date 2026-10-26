
void FUN_0083f0d0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_3 != param_4) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    puVar2 = param_3;
    while (param_4 != puVar1) {
      puVar3 = param_4 + 0x1e;
      puVar5 = puVar2 + 0x1e;
      puVar6 = param_4;
      puVar7 = puVar2;
      for (iVar4 = 0x1e; param_4 = puVar3, puVar2 = puVar5, iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    FUN_00840d00(*(undefined4 *)(param_1 + 4),param_1);
    *(undefined4 **)(param_1 + 4) = puVar2;
  }
  *param_2 = param_3;
  return;
}

