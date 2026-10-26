
void FUN_00763c90(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_0090ed6d;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIImageSetGroup::vftable;
  local_8 = 1;
  puVar2 = (undefined4 *)in_ECX[3];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    iVar4 = puVar3[4];
    if (*(char *)(iVar4 + 0x98) != '\0') {
      if (*(int **)(iVar4 + 8) != (int *)0x0) {
        (**(code **)(**(int **)(iVar4 + 8) + 8))(uVar7);
        *(undefined4 *)(iVar4 + 8) = 0;
      }
      *(undefined4 *)(iVar4 + 0x58) = 0;
      *(undefined4 *)(iVar4 + 0x5c) = 0;
      *(undefined1 *)(iVar4 + 0x98) = 0;
    }
    if ((int *)puVar3[4] != (int *)0x0) {
      (**(code **)(*(int *)puVar3[4] + 0x1c))(1);
      puVar3[4] = 0;
    }
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
  FUN_00823850();
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  FUN_0089120c(in_ECX[3]);
  *in_ECX = FoxUI::FXUIArchive::vftable;
  ExceptionList = local_10;
  return;
}

