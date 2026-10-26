
void FUN_007d5cd0(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_EAX;
  int iVar6;
  undefined4 uVar7;
  int local_c;
  int local_8;
  
  puVar2 = *(undefined4 **)(in_EAX + 0x40);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (param_1 != 0) {
      local_8 = puVar3[4];
      FUN_0082ef00(&local_8);
      if ((local_c != *(int *)(param_1 + 0xd8)) &&
         (iVar6 = (**(code **)(**(int **)(local_c + 0x10) + 8))(), iVar6 == local_8)) {
        (**(code **)(**(int **)(local_c + 0x10) + 0x24))();
      }
    }
    uVar7 = FUN_0057ef20();
    FUN_0082f200(param_2,uVar7);
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}

