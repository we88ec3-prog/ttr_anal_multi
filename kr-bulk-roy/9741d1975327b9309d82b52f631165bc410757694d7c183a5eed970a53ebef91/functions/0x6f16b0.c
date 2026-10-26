
uint FUN_006f16b0(int param_1)

{
  char cVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  uint local_8;
  
  local_8 = 0;
  piVar5 = (int *)(param_1 + 8);
  iVar4 = 5;
  do {
    if (*piVar5 != 0) {
      uVar2 = (**(code **)(*(int *)*piVar5 + 0x18))();
      local_8 = local_8 | uVar2;
    }
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_006f1790(param_1);
  uVar2 = 0;
  do {
    if ((((*(int *)(param_1 + 0x20) != 0) && ((uVar2 & 0xff) < 0x100)) &&
        ((cVar1 = *(char *)((uVar2 & 0xff) + 0x160 + param_1), cVar1 == '\x01' || (cVar1 == '\x03'))
        )) && (iVar4 = 0, -1 < *(int *)(param_1 + 0x578))) {
      piVar5 = (int *)(param_1 + 0x4f8);
      do {
        if (*piVar5 != 0) {
          if (cVar1 == '\x01') {
            pcVar3 = (code *)**(undefined4 **)*piVar5;
          }
          else {
            if (cVar1 != '\x03') goto LAB_006f1754;
            pcVar3 = *(code **)(*(int *)*piVar5 + 4);
          }
          (*pcVar3)(uVar2);
        }
LAB_006f1754:
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 <= *(int *)(param_1 + 0x578));
    }
    uVar2 = uVar2 + 1;
    if (0xff < (int)uVar2) {
      return -(uint)(local_8 != 0) & 0x80004005;
    }
  } while( true );
}

