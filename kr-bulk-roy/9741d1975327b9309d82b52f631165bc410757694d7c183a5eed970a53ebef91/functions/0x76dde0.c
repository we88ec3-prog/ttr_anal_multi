
int * FUN_0076dde0(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = _malloc(0xc);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar2[1] = DAT_00fba828;
    piVar2[2] = 6;
    *piVar2 = (int)FoxUI::FXUIDockInfoOutter::vftable;
  }
  (**(code **)(*piVar2 + 0x34))();
  piVar2[1] = *(int *)(in_ECX + 4);
  pcVar1 = *(code **)(*piVar2 + 0x38);
  piVar2[2] = *(int *)(in_ECX + 8);
  (*pcVar1)();
  return piVar2;
}

