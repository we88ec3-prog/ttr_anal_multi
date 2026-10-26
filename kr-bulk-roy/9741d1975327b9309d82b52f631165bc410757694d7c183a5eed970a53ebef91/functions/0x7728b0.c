
void FUN_007728b0(void)

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
  puStack_c = &LAB_0090ec5d;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIManagerContainer<unsigned_int,FoxUI::FXUILocale>::vftable;
  local_8 = 1;
  puVar2 = (undefined4 *)in_ECX[2];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    puVar4 = (undefined4 *)puVar3[4];
    if (puVar4 != (undefined4 *)0x0) {
      if (7 < (uint)puVar4[0xc]) {
        FUN_0089120c(puVar4[7],uVar6);
      }
      puVar4[0xc] = 7;
      puVar4[0xb] = 0;
      *(undefined2 *)(puVar4 + 7) = 0;
      if (7 < (uint)puVar4[5]) {
        FUN_0089120c(*puVar4,uVar6);
      }
      puVar4[5] = 7;
      puVar4[4] = 0;
      *(undefined2 *)puVar4 = 0;
      FUN_0089120c(puVar4,uVar6);
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
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  FUN_0089120c(in_ECX[2],uVar6);
  *in_ECX = FoxUI::FXUIManager::vftable;
  ExceptionList = local_10;
  return;
}

