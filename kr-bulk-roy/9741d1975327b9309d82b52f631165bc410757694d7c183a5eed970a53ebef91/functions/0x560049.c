
void FUN_00560049(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  
  piVar3 = (int *)(unaff_EDI + 0x48);
  piVar1 = piVar3;
  if (0xf < *(uint *)(unaff_EDI + 0x5c)) {
    piVar1 = (int *)*piVar3;
  }
  iVar2 = FUN_00734330(piVar1,0);
  *(int *)(unaff_EDI + 0x44) = iVar2;
  if (iVar2 == 0) {
    if (0xf < *(uint *)(unaff_EDI + 0x5c)) {
      piVar3 = (int *)*piVar3;
    }
    FUN_006edb60("CFlyingImage::Load(): Can\'t load texture file \'%s\'",piVar3);
  }
  *(undefined4 *)(unaff_EDI + 0x34) = 1;
  return;
}

