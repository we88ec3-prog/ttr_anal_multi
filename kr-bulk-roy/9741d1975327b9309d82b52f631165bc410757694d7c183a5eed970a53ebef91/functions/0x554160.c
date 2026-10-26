
void FUN_00554160(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (unaff_ESI[2] == 0) {
    iVar1 = FUN_00734330("Contents_Class.dds","UI/ImageSets");
    *unaff_ESI = iVar1;
    iVar1 = FUN_00734330("Contents_Class2.dds","UI/ImageSets");
    unaff_ESI[1] = iVar1;
    if ((*unaff_ESI != 0) && (iVar1 != 0)) {
      unaff_ESI[2] = 1;
    }
  }
  return;
}

