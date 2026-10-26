
void FUN_007f4bf0(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  int *local_220;
  char local_21c [264];
  char local_114;
  undefined1 local_113 [255];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009375ce;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_220 = (int *)(unaff_ESI + 0x308);
  iVar4 = 0;
  local_14 = uVar1;
  do {
    if (*local_220 != 0) {
      local_114 = '\0';
      _memset(local_113,0,0xff);
      if (*(int *)(unaff_ESI + 0x33c) == 1) {
        piVar2 = (int *)(unaff_ESI + 800);
        if (0xf < *(uint *)(unaff_ESI + 0x334)) {
          piVar2 = (int *)*piVar2;
        }
        _sprintf(&local_114,"Map/Skybox/%s%s.dds",piVar2,(&PTR_DAT_00d63a48)[iVar4]);
      }
      else {
        piVar2 = (int *)(unaff_ESI + 800);
        if (*(int *)(unaff_ESI + 0x33c) == 2) {
          if (0xf < *(uint *)(unaff_ESI + 0x334)) {
            piVar2 = (int *)*piVar2;
          }
          _sprintf(&local_114,"Map/Skybox/%s%d.dds",piVar2,iVar4);
        }
        else {
          if (0xf < *(uint *)(unaff_ESI + 0x334)) {
            piVar2 = (int *)*piVar2;
          }
          _sprintf(&local_114,"Map/Skybox/%s.dds",piVar2);
        }
      }
      __splitpath(&local_114,(char *)0x0,(char *)0x0,local_21c,(char *)0x0);
      if ((DAT_00fe1ac0 & 1) == 0) {
        DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
        local_8 = 0;
        FUN_007bb970();
        _atexit((_func_4879 *)&LAB_00bceac0);
        local_8 = 0xffffffff;
      }
      iVar3 = FUN_007bcf60();
      if (iVar3 != 0) {
        *local_220 = 0;
      }
    }
    local_220 = local_220 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  piVar2 = *(int **)(unaff_ESI + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,uVar1);
    *(undefined4 *)(unaff_ESI + 4) = 0;
  }
  *(undefined1 *)(unaff_ESI + 0x34c) = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

