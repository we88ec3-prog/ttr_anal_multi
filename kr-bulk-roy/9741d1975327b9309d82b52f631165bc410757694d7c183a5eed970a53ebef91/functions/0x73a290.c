
undefined4 FUN_0073a290(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b1ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 0;
    FUN_00736880(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce6f0);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)(unaff_ESI + 0x4c);
  uVar3 = D3DXCreateTexture(DAT_00fcde2c,*(undefined4 *)(unaff_ESI + 0xc),
                            *(undefined4 *)(unaff_ESI + 0x10),*(undefined4 *)(unaff_ESI + 0x9c),
                            -(uint)(*(int *)(unaff_ESI + 0x98) != 0) & 0x400 | 1,
                            *(undefined4 *)(unaff_ESI + 0x48),0,piVar1);
  FUN_00733f90(uVar3,0);
  if (*(int *)(unaff_ESI + 0x98) != 0) {
    (**(code **)(*(int *)*piVar1 + 0x38))((int *)*piVar1,2);
  }
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x44))(piVar2,0,unaff_ESI + 0x50);
    (**(code **)(*(int *)*piVar1 + 0x48))((int *)*piVar1,0,unaff_ESI + 0x70);
    *(undefined4 *)(unaff_ESI + 0x94) = 1;
    ExceptionList = local_10;
    return 1;
  }
  ExceptionList = local_10;
  return 0;
}

