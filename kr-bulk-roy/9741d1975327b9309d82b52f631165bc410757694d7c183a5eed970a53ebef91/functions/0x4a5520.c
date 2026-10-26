
void FUN_004a5520(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined1 *local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933f8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 0x110) == '\0') {
    if ((DAT_00fd93f4 & 1) == 0) {
      DAT_00fd93f4 = DAT_00fd93f4 | 1;
      local_1c = &stack0xffffffcc;
      local_8 = 0;
      FUN_00828c00();
      _atexit(FUN_00bcde40);
    }
    local_8 = 0xffffffff;
    piVar4 = (int *)*DAT_00fd93fc;
    if (*(int *)(*(int *)(param_1 + 0xfc) + 0xcc) != 0) {
      FUN_006438f0();
    }
    while (piVar4 != DAT_00fd93fc) {
      iVar6 = *(int *)(param_1 + 0x108);
      FUN_004a4cc0();
      if (local_1c == *(undefined1 **)(iVar6 + 4)) {
        iVar6 = 0;
LAB_004a5730:
        if (piVar4[0x20] != 2) goto LAB_004a573d;
      }
      else {
        iVar6 = *(int *)(local_1c + 0x10);
        if (iVar6 == 0) goto LAB_004a5730;
LAB_004a573d:
        if (*(int *)(*(int *)(param_1 + 0xfc) + 0xcc) == 0) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = (int *)FUN_00412c70();
        }
        if (iVar6 == 0) {
          FUN_004a5110();
          (**(code **)(*(int *)piVar7[0x92] + 0x94))();
          (**(code **)(*(int *)piVar7[0x92] + 200))();
          (**(code **)(*(int *)piVar7[0x94] + 0x94))(*(undefined1 *)(piVar7[0x95] + 0x68));
          (**(code **)(*(int *)piVar7[0x94] + 200))();
        }
        else {
          FUN_004a5110();
          (**(code **)(*(int *)piVar7[0x92] + 0x94))();
          (**(code **)(*(int *)piVar7[0x92] + 200))();
          (**(code **)(*(int *)piVar7[0x94] + 0x94))(*(undefined1 *)(piVar7[0x95] + 0x68));
          (**(code **)(*(int *)piVar7[0x94] + 200))();
        }
        (**(code **)(*piVar7 + 200))();
      }
      FUN_004a62d0();
    }
    FUN_00749920();
    piVar4 = *(int **)(param_1 + 0xfc);
  }
  else {
    iVar6 = *(int *)(param_1 + 0x108);
    piVar4 = (int *)**(int **)(iVar6 + 4);
    iVar2 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
    iVar5 = 0;
    if (iVar2 != 0) {
      FUN_00408920(iVar2);
    }
    if (piVar4 != *(int **)(iVar6 + 4)) {
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
        if (((iVar2 == 0) || (iVar5 < 0)) ||
           (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2 <= iVar5)) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = *(int **)(*(int *)(iVar2 + 0xa8) + iVar5 * 4);
        }
        FUN_004a5110();
        (**(code **)(*(int *)piVar7[0x92] + 0x94))();
        (**(code **)(*(int *)piVar7[0x92] + 200))();
        (**(code **)(*(int *)piVar7[0x94] + 0x94))(*(undefined1 *)(piVar7[0x95] + 0x68));
        (**(code **)(*(int *)piVar7[0x94] + 200))();
        (**(code **)(*piVar7 + 200))();
        iVar5 = iVar5 + 1;
        if (*(char *)((int)piVar4 + 0x15) == '\0') {
          piVar7 = (int *)piVar4[2];
          if (*(char *)((int)piVar7 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar7 + 0x15);
            piVar4 = piVar7;
            piVar7 = (int *)*piVar7;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar7 + 0x15);
              piVar4 = piVar7;
              piVar7 = (int *)*piVar7;
            }
          }
          else {
            cVar1 = *(char *)(piVar4[1] + 0x15);
            piVar3 = (int *)piVar4[1];
            piVar7 = piVar4;
            while ((piVar4 = piVar3, cVar1 == '\0' && (piVar7 == (int *)piVar4[2]))) {
              cVar1 = *(char *)(piVar4[1] + 0x15);
              piVar3 = (int *)piVar4[1];
              piVar7 = piVar4;
            }
          }
        }
      } while (piVar4 != *(int **)(iVar6 + 4));
    }
    FUN_00749920();
    piVar4 = *(int **)(param_1 + 0xfc);
  }
  (**(code **)(*piVar4 + 200))();
  ExceptionList = local_10;
  return;
}

