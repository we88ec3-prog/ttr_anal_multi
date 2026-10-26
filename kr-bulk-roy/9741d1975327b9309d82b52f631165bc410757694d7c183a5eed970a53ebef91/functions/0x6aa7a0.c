
void FUN_006aa7a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = FUI::CGuildMarkUpload::vftable;
  if (7 < (uint)in_ECX[0x46]) {
    FUN_0089120c(in_ECX[0x41]);
  }
  in_ECX[0x46] = 7;
  in_ECX[0x45] = 0;
  *(undefined2 *)(in_ECX + 0x41) = 0;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  return;
}

