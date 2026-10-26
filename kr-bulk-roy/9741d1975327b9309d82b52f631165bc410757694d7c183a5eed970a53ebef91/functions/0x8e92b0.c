
void FUN_008e92b0(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_ESI;
  undefined1 local_5e4 [40];
  int local_5bc;
  undefined1 local_5a0;
  undefined1 local_59e;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(unaff_ESI + 0x1e8);
  *unaff_EBX = 0;
  iVar2 = (*(code *)**(undefined4 **)(iVar1 + 0xc))(local_5e4);
  if (iVar2 == 0) {
    local_8c = *(undefined4 *)(unaff_ESI + 0x198);
    local_88 = *(undefined4 *)(unaff_ESI + 0x19c);
    local_5a0 = 0;
    local_90 = *(undefined4 *)(unaff_ESI + 0x194);
    local_14 = *(undefined4 *)(unaff_ESI + 0x220);
    local_10 = *(undefined4 *)(unaff_ESI + 0x21c);
    *unaff_EBX = 0;
    local_59e = 1;
    if (0 < *(int *)(unaff_ESI + 0x1a0)) {
      iVar2 = 0;
      do {
        FUN_008e9260(local_5e4,iVar2);
        if ((iVar2 == 0) || (*unaff_EBX < local_5bc)) {
          *unaff_EBX = local_5bc;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(unaff_ESI + 0x1a0));
    }
    (**(code **)(*(int *)(iVar1 + 0xc) + 4))(local_5e4);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

