
void FUN_008481e0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_3 != param_4) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    puVar2 = param_3;
    while (param_4 != puVar1) {
      puVar4 = param_4 + 0xd;
      puVar5 = puVar2 + 0xd;
      puVar6 = param_4;
      puVar7 = puVar2;
      for (iVar3 = 0xd; param_4 = puVar4, puVar2 = puVar5, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    *(undefined4 **)(param_1 + 4) = puVar2;
  }
  *param_2 = param_3;
  return;
}

