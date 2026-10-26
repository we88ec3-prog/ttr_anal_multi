
void FUN_007631f0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_0090c87e;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIImageSet::vftable;
  local_8 = 4;
  puVar2 = (undefined4 *)in_ECX[0x13];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if ((int *)puVar3[4] != (int *)0x0) {
      (**(code **)(*(int *)puVar3[4] + 0x1c))(1,uVar6);
      puVar3[4] = 0;
    }
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
  FUN_00823850();
  in_ECX[0x18] = FoxUI::FXUIImageSetItem::vftable;
  if (7 < (uint)in_ECX[0x20]) {
    FUN_0089120c(in_ECX[0x1b]);
  }
  in_ECX[0x20] = 7;
  in_ECX[0x1f] = 0;
  *(undefined2 *)(in_ECX + 0x1b) = 0;
  in_ECX[0x18] = FoxUI::FXUIArchive::vftable;
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_005540c0(*(undefined4 *)in_ECX[0x13],(undefined4 *)in_ECX[0x13]);
  FUN_0089120c(in_ECX[0x13]);
  if (7 < (uint)in_ECX[0x10]) {
    FUN_0089120c(in_ECX[0xb]);
  }
  in_ECX[0x10] = 7;
  in_ECX[0xf] = 0;
  *(undefined2 *)(in_ECX + 0xb) = 0;
  if (7 < (uint)in_ECX[9]) {
    FUN_0089120c(in_ECX[4]);
  }
  in_ECX[9] = 7;
  in_ECX[8] = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  *in_ECX = FoxUI::FXUIArchive::vftable;
  ExceptionList = local_10;
  return;
}

