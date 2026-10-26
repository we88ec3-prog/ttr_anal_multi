
/* WARNING: Removing unreachable block (ram,0x008179c8) */
/* WARNING: Removing unreachable block (ram,0x008179d8) */
/* WARNING: Removing unreachable block (ram,0x008179e1) */
/* WARNING: Removing unreachable block (ram,0x008179e4) */
/* WARNING: Removing unreachable block (ram,0x008179d4) */
/* WARNING: Removing unreachable block (ram,0x008179f2) */
/* WARNING: Removing unreachable block (ram,0x00817a02) */
/* WARNING: Removing unreachable block (ram,0x00817a0d) */
/* WARNING: Removing unreachable block (ram,0x00817a09) */
/* WARNING: Removing unreachable block (ram,0x008179fd) */
/* WARNING: Removing unreachable block (ram,0x00817a10) */

void FUN_00817900(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x15) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0049e6a0();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x15) == '\0') {
    if (*(char *)(param_2[2] + 0x15) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x15) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fb11b0[1] == param_2) {
    DAT_00fb11b0[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fb11b0 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x15) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x15);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x15);
        piVar5 = piVar3;
      }
    }
    *DAT_00fb11b0 = piVar5;
  }
  if ((int *)DAT_00fb11b0[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x15) == '\0') {
      uVar4 = FUN_00823b80();
      DAT_00fb11b0[2] = uVar4;
    }
    else {
      DAT_00fb11b0[2] = piVar6;
    }
  }
  if ((char)param_2[5] == '\x01') {
    if (piVar7 != (int *)DAT_00fb11b0[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[5] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[5] == '\0') {
            *(undefined1 *)(piVar6 + 5) = 1;
            *(undefined1 *)(piVar5 + 5) = 0;
            FUN_00763f60(&DAT_00fb11ac);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x15) == '\0') {
            if ((*(char *)(*piVar6 + 0x14) != '\x01') || (*(char *)(piVar6[2] + 0x14) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x14) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x14) = 1;
                *(undefined1 *)(piVar6 + 5) = 0;
                FUN_0043e670(&DAT_00fb11ac);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 5) = (char)piVar5[5];
              *(undefined1 *)(piVar5 + 5) = 1;
              *(undefined1 *)(piVar6[2] + 0x14) = 1;
              FUN_00763f60(&DAT_00fb11ac);
              break;
            }
LAB_00817af7:
            *(undefined1 *)(piVar6 + 5) = 0;
          }
        }
        else {
          if ((char)piVar6[5] == '\0') {
            *(undefined1 *)(piVar6 + 5) = 1;
            *(undefined1 *)(piVar5 + 5) = 0;
            FUN_0043e670(&DAT_00fb11ac);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x15) == '\0') {
            if ((*(char *)(piVar6[2] + 0x14) == '\x01') && (*(char *)(*piVar6 + 0x14) == '\x01'))
            goto LAB_00817af7;
            if (*(char *)(*piVar6 + 0x14) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x14) = 1;
              *(undefined1 *)(piVar6 + 5) = 0;
              FUN_00763f60(&DAT_00fb11ac);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 5) = (char)piVar5[5];
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(*piVar6 + 0x14) = 1;
            FUN_0043e670(&DAT_00fb11ac);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fb11b0[1]);
    }
    *(undefined1 *)(piVar7 + 5) = 1;
  }
  FUN_0089120c(param_2);
  if (DAT_00fb11b4 != 0) {
    DAT_00fb11b4 = DAT_00fb11b4 + -1;
  }
  *param_1 = param_2;
  return;
}

