
void FUN_008fde00(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar2 = FUN_00734330("UI/ImageSets/RandomItem_Frame.dds",0);
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  uVar2 = FUN_00734330("UI/ImageSets/OutlineEffect.dds",0);
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  FUN_00572110();
  FUN_00572100();
  cVar1 = FUN_00572220();
  while (cVar1 != '\0') {
    thunk_FUN_00572200();
    FUN_008fd200();
    FUN_005721f0();
    cVar1 = FUN_00572220();
  }
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  return;
}

