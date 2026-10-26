
void FUN_0057f670(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ccab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(unaff_EDI + 0x74) != 0) {
    *(int **)(unaff_EDI + 4) = param_1;
    (**(code **)(*param_1 + 0xc))(param_1);
    puVar2 = *(undefined4 **)(unaff_EDI + 0x38);
    for (puVar4 = *(undefined4 **)(unaff_EDI + 0x34); puVar4 != puVar2; puVar4 = puVar4 + 1) {
      (*(code *)**(undefined4 **)*puVar4)();
    }
    iVar1 = *(int *)(unaff_EDI + 0x68);
    if (iVar1 != 0) {
      puVar2 = (undefined4 *)(iVar1 + 8);
      if (0xf < *(uint *)(iVar1 + 0x1c)) {
        puVar2 = (undefined4 *)*puVar2;
      }
      uVar3 = FUN_00734330(puVar2,0);
      *(undefined4 *)(unaff_EDI + 0x10) = uVar3;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x48);
    local_8 = 0;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      FUN_00734010();
      *puVar2 = Synopsis::CTextMask::vftable;
      puVar2[1] = Synopsis::CTextMask::vftable;
      puVar2[2] = Synopsis::CTextMask::vftable;
    }
    local_8 = 0xffffffff;
    *(undefined4 **)(unaff_EDI + 0x14) = puVar2;
    FUN_00580280();
    *(undefined4 *)(unaff_EDI + 0x78) = 1;
  }
  ExceptionList = local_10;
  return;
}

