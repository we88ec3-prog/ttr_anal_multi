
void FUN_0042e340(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int unaff_EDI;
  uint uVar4;
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
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = *(int *)(unaff_EDI + 0xf8);
  uVar4 = uVar3;
  if (*(char *)(iVar2 + 0x141) == '\0') {
    FUN_00757710(uVar3);
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar2 + 0x168) = 0;
  *(undefined4 *)(iVar2 + 0x160) = 0;
  *(undefined4 *)(iVar2 + 0x164) = 0;
  *(undefined4 *)(iVar2 + 0x14c) = 0;
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  FUN_004068f0();
  local_8 = 0;
  iVar2 = *(int *)(unaff_EDI + 0xfc);
  if (*(char *)(iVar2 + 0x141) == '\0') {
    FUN_00757710(uVar4);
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar2 + 0x168) = 0;
  *(undefined4 *)(iVar2 + 0x160) = 0;
  *(undefined4 *)(iVar2 + 0x164) = 0;
  *(undefined4 *)(iVar2 + 0x14c) = 0;
  local_8 = 0xffffffff;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  (**(code **)(**(int **)(unaff_EDI + 0xfc) + 200))();
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
    iVar2 = *local_50;
    if (*(char *)(iVar2 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar2 + 0x168) = 0;
    *(undefined4 *)(iVar2 + 0x160) = 0;
    *(undefined4 *)(iVar2 + 0x164) = 0;
    *(undefined4 *)(iVar2 + 0x14c) = 0;
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_50 = local_50 + 1;
    local_54 = local_54 + 1;
  } while (local_54 < 3);
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

