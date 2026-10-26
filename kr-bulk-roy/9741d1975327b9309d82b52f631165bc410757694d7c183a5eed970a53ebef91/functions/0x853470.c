
void FUN_00853470(int *param_1,int *param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *unaff_EDI;
  undefined1 local_8 [4];
  
  piVar2 = param_1;
  do {
    do {
      while( true ) {
        do {
          while( true ) {
            piVar5 = param_1;
            if ((piVar5 == param_2) || (param_3 == param_4)) {
              *unaff_EDI = param_5;
              unaff_EDI[1] = param_6;
              return;
            }
            param_1 = piVar5;
            if ((uint)piVar5[3] < *(uint *)(param_3 + 0xc)) break;
            if (*(uint *)(param_3 + 0xc) < (uint)piVar5[3]) {
              FUN_0079c460();
            }
            else {
              FUN_0079c460();
              puVar4 = (undefined4 *)FUN_00853b30(local_8,param_6);
              param_6 = *puVar4;
              FUN_0079c460();
              FUN_0079c460();
              param_1 = piVar2;
            }
          }
        } while (*(char *)((int)piVar5 + 0x11) != '\0');
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x11) != '\0') break;
        cVar1 = *(char *)(*piVar2 + 0x11);
        piVar5 = (int *)*piVar2;
        while (param_1 = piVar2, cVar1 == '\0') {
          cVar1 = *(char *)(*piVar5 + 0x11);
          piVar2 = piVar5;
          piVar5 = (int *)*piVar5;
        }
      }
      param_1 = (int *)piVar5[1];
      piVar2 = param_1;
    } while (*(char *)((int)param_1 + 0x11) != '\0');
    do {
      piVar3 = param_1;
      param_1 = piVar3;
      piVar2 = piVar3;
      if (piVar5 != (int *)piVar3[2]) break;
      piVar2 = (int *)piVar3[1];
      param_1 = piVar2;
      piVar5 = piVar3;
    } while (*(char *)((int)piVar2 + 0x11) == '\0');
  } while( true );
}

