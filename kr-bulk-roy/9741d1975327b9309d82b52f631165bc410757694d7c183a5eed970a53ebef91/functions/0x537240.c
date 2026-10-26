
void FUN_00537240(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  void **ppvVar7;
  uint uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090fec7;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 1;
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  puVar3 = (undefined4 *)*puVar2;
  ppvVar7 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar7, puVar3 != puVar2) {
    iVar4 = puVar3[4];
    if (iVar4 != 0) {
      FUN_00536ff0(uVar8);
      FUN_0089120c(iVar4);
    }
    ppvVar7 = ExceptionList;
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x15);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  uVar8 = (uint)local_8 >> 8;
  local_8 = CONCAT31((int3)uVar8,2);
  FUN_005540c0(**(undefined4 **)(param_1 + 0x14),*(undefined4 **)(param_1 + 0x14));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x14));
  local_8 = 3;
  FUN_0051af60(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_0089120c(*(undefined4 *)(param_1 + 4));
  ExceptionList = local_10;
  return;
}

