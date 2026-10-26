
void FUN_0074f0f0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *unaff_ESI;
  int local_c;
  int *local_8;
  
  local_8 = (int *)(param_1 + 0x1338);
  piVar3 = (int *)(param_1 + 0x134c);
  local_c = 3;
  do {
    iVar2 = *(int *)(param_1 + 0xfc + *local_8 * 4);
    if (iVar2 == 1) {
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) {
LAB_0074f16b:
        piVar1 = (int *)0x0;
      }
      else {
        iVar2 = piVar3[-2];
LAB_0074f14f:
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = unaff_ESI[8];
        piVar1[2] = unaff_ESI[0x12];
        piVar1[3] = (int)unaff_ESI;
        piVar1[4] = iVar2;
      }
      (**(code **)(*unaff_ESI + 0x144))(piVar1);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
      }
    }
    else if (iVar2 == 6) {
      piVar1 = (int *)FUN_00891268(0x14);
      if (piVar1 == (int *)0x0) goto LAB_0074f16b;
      iVar2 = *piVar3;
      goto LAB_0074f14f;
    }
    local_8 = local_8 + 1;
    piVar3 = piVar3 + 6;
    local_c = local_c + -1;
    if (local_c == 0) {
      return;
    }
  } while( true );
}

