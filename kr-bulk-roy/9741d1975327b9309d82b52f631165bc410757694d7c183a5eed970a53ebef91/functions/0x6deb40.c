
undefined4 FUN_006deb40(void)

{
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = (**(code **)(*unaff_ESI + 0x20))();
  if (iVar1 == 0) {
    if (DAT_00fba7cc == 0) {
      iVar1 = FUN_00891268(0x1380);
      if (iVar1 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    FUN_006e1860();
    FUN_006e1930();
    FUN_006e1a00();
    FUN_006e1ad0();
    FUN_006e1ee0();
    FUN_006e1e10();
    FUN_006e1d40();
    FUN_006e1ba0();
    FUN_006e1c70();
    FUN_006e0270();
    FUN_006e1fb0();
    FUN_006e5c60();
    FUN_006e24d0(unaff_ESI[10],unaff_ESI[0xe],unaff_ESI[0xf]);
    iVar1 = FUN_006dfd60();
    unaff_ESI[2] = iVar1;
    (**(code **)(*unaff_ESI + 0x28))();
    FUN_006e2850(unaff_ESI[0xe],unaff_ESI[0xf],FUN_006eae10,FUN_006eae50);
    return 0;
  }
  FID_conflict__wprintf("Error from CFramework::OnInitScene(): %s\n",unaff_ESI + 0x10);
  unaff_ESI[0xb] = 1;
  return 0x80004005;
}

