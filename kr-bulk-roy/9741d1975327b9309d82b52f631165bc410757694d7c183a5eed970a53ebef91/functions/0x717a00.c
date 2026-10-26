
void FUN_00717a00(void)

{
  undefined4 *unaff_ESI;
  
  *(undefined8 *)(unaff_ESI + 0x44) = 0x409f640000000000;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  _memset(unaff_ESI + 3,0,0x100);
  unaff_ESI[0x46] = 0;
  unaff_ESI[0x47] = 0;
  unaff_ESI[0x48] = 0;
  *unaff_ESI = Package::FileNode::vftable;
  return;
}

