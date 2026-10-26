
void FUN_00419110(uint param_1)

{
  ushort uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x57b) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xb8) + 0x20)) {
      uVar1 = *(ushort *)(*(int *)(in_ECX + 0x88 + *(int *)(in_ECX + 0xbc) * 4) + 0x298);
      iVar2 = FUN_00404ba0();
      iVar2 = *(int *)(iVar2 + 0x6928);
      param_1 = (uint)uVar1;
      FUN_004a4cc0(&param_1);
      if (((in_ECX != *(int *)(iVar2 + 0x14)) && (*(int *)(in_ECX + 0x10) != 0)) &&
         (*(int *)(*(int *)(in_ECX + 0x10) + 0xc) != 0)) {
        FUN_004054c0();
        FUN_0058b0a0(0xf43bb,*(undefined4 *)
                              (*(int *)(in_ECX + 0x88 + *(int *)(in_ECX + 0xbc) * 4) + 0x250));
        return;
      }
    }
  }
  else if ((*(int *)(param_1 + 0x10) == 0x70b) &&
          (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x84) + 0x20))) {
    iVar2 = FUN_004068c0();
    *(undefined4 *)(in_ECX + 0xbc) = *(undefined4 *)(iVar2 + 0x14);
    FUN_004191f0(in_ECX);
  }
  return;
}

