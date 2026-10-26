
void FUN_005f4190(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int local_10;
  
  FUN_007545b0();
  FUN_00749d00();
  FUN_00749a00(0,0x1e);
  FUN_00749d00();
  local_10 = 0;
  piVar2 = (int *)(in_ECX + 0x230);
  do {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x198) + 0x14) + 10 + local_10;
    FUN_00749a00(*(undefined4 *)(piVar2[-9] + 8),iVar1);
    FUN_00749a00(*(undefined4 *)(*piVar2 + 8),iVar1);
    FUN_00749a00(*(undefined4 *)(piVar2[3] + 8),iVar1 + 0x14);
    local_10 = local_10 + 0x3c;
    piVar2 = piVar2 + 1;
  } while (local_10 < 0xb4);
  return;
}

