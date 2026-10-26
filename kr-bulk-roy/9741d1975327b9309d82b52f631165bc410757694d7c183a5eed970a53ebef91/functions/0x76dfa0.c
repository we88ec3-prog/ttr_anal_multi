
int * FUN_0076dfa0(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = _malloc(0x20);
  piVar2 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar1[1] = DAT_00fba828;
    piVar1[2] = 6;
    *piVar1 = (int)FoxUI::FXUIDockInfoGuide::vftable;
    piVar1[6] = 0;
    piVar1[5] = 0;
    piVar1[4] = 0;
    piVar1[3] = 0;
    piVar1[7] = 6;
    piVar2 = piVar1;
  }
  (**(code **)(*piVar2 + 0x34))();
  piVar2[1] = *(int *)(in_ECX + 4);
  piVar2[2] = *(int *)(in_ECX + 8);
  piVar2[3] = *(int *)(in_ECX + 0xc);
  piVar2[4] = *(int *)(in_ECX + 0x10);
  piVar2[5] = *(int *)(in_ECX + 0x14);
  piVar2[6] = *(int *)(in_ECX + 0x18);
  piVar2[7] = *(int *)(in_ECX + 0x1c);
  (**(code **)(*piVar2 + 0x38))();
  return piVar2;
}

