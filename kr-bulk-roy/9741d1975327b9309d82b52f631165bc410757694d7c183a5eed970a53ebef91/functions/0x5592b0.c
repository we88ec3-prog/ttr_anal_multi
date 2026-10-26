
void FUN_005592b0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = FUN_00734330("Kills.dds","UI/ImageSets");
  *(undefined4 *)(unaff_ESI + 0x10) = uVar1;
  uVar1 = FUN_00734330("Num_Kills.dds","UI/ImageSets");
  *(undefined4 *)(unaff_ESI + 0x30) = uVar1;
  uVar1 = FUN_00734330("Critical.dds","UI/ImageSets");
  *(undefined4 *)(unaff_ESI + 0x38) = uVar1;
  uVar1 = FUN_00734330("Critical_Line.dds","UI/ImageSets");
  *(undefined4 *)(unaff_ESI + 0x58) = uVar1;
  uVar1 = FUN_00734330("AttackedFX.dds","UI/ImageSets");
  *(undefined4 *)(unaff_ESI + 0x78) = uVar1;
  return;
}

