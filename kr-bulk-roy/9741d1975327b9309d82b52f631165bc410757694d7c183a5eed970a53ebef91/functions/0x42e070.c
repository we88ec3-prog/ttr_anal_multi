
void FUN_0042e070(void)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  uint uVar6;
  int local_54;
  int *local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b570;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = *(int *)(unaff_EDI + 0xf8);
  *(undefined1 *)(unaff_EDI + 0x15a) = 0;
  uVar6 = uVar2;
  if (*(char *)(iVar4 + 0x141) == '\0') {
    puVar3 = (undefined4 *)(iVar4 + 0x108);
    if (7 < *(uint *)(iVar4 + 0x11c)) {
      puVar3 = (undefined4 *)*puVar3;
    }
  }
  else {
    FUN_006edb10("Not supported operation",uVar2);
    if (*(uint *)(iVar4 + 0x11c) < 8) {
      puVar3 = (undefined4 *)(iVar4 + 0x108);
    }
    else {
      puVar3 = *(undefined4 **)(iVar4 + 0x108);
    }
  }
  if (*(uint *)(unaff_EDI + 0x14c) < 8) {
    puVar5 = (undefined4 *)(unaff_EDI + 0x138);
  }
  else {
    puVar5 = *(undefined4 **)(unaff_EDI + 0x138);
  }
  if (puVar3 != puVar5) {
    *(undefined1 *)(unaff_EDI + 0x15a) = 1;
  }
  iVar4 = *(int *)(unaff_EDI + 0xfc);
  if (*(char *)(iVar4 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",uVar6);
  }
  iVar4 = FUN_00432b90(iVar4 + 0x108);
  if (iVar4 != *(int *)(unaff_EDI + 0x154)) {
    *(undefined1 *)(unaff_EDI + 0x15a) = 1;
  }
  iVar4 = *(int *)(unaff_EDI + 0xf8);
  if (*(char *)(iVar4 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation",uVar6);
  }
  *(undefined4 *)(iVar4 + 0x168) = 0;
  *(undefined4 *)(iVar4 + 0x160) = 0;
  *(undefined4 *)(iVar4 + 0x164) = 0;
  *(undefined4 *)(iVar4 + 0x14c) = 0;
  FUN_004068f0();
  local_8 = 0;
  iVar4 = *(int *)(unaff_EDI + 0xfc);
  if (*(char *)(iVar4 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar4 + 0x168) = 0;
  *(undefined4 *)(iVar4 + 0x160) = 0;
  *(undefined4 *)(iVar4 + 0x164) = 0;
  *(undefined4 *)(iVar4 + 0x14c) = 0;
  local_8 = 0xffffffff;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  FUN_0075cc70(*(undefined4 *)(unaff_EDI + 0x100),(&PTR_DAT_00d6a218)[*(byte *)(unaff_EDI + 0x130)])
  ;
  FUN_0042dbf0(*(char *)(unaff_EDI + 0x130) == '\x02');
  cVar1 = *(char *)(unaff_EDI + 0x158);
  (**(code **)(**(int **)(unaff_EDI + 0x104) + 0xa0))(cVar1);
  (**(code **)(**(int **)(unaff_EDI + 0x108) + 0xa0))(cVar1 == '\0');
  local_50 = (int *)(unaff_EDI + 0x11c);
  local_54 = 0;
  do {
    FUN_00426ec0();
    local_8 = 1;
    iVar4 = *local_50;
    if (*(char *)(iVar4 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar4 + 0x168) = 0;
    *(undefined4 *)(iVar4 + 0x160) = 0;
    *(undefined4 *)(iVar4 + 0x164) = 0;
    *(undefined4 *)(iVar4 + 0x14c) = 0;
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_50 = local_50 + 1;
    local_54 = local_54 + 1;
  } while (local_54 < 3);
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

