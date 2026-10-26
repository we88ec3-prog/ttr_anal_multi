
int FUN_006f4cd0(int *param_1,int param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  double *pdVar5;
  undefined8 *puVar6;
  char *in_EDX;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  
  iVar7 = param_2;
  param_2 = 0;
  if (in_EDX == (char *)0x0) {
    return 0;
  }
  if (*in_EDX != '\0') {
    iVar8 = iVar7 + -4;
    iVar7 = iVar7 + -8;
    do {
      if (*in_EDX == ')') {
        return param_2;
      }
      if (*in_EDX == '%') {
        cVar3 = in_EDX[1];
        in_EDX = in_EDX + 1;
        if (cVar3 == 'd') {
          piVar1 = (int *)(iVar8 + 4);
          iVar4 = *param_1;
          pdVar5 = *(double **)(iVar4 + 8);
          iVar8 = iVar8 + 4;
          *pdVar5 = (double)*piVar1;
          iVar7 = iVar7 + 4;
          *(undefined4 *)(pdVar5 + 1) = 3;
          piVar1 = (int *)(iVar4 + 8);
          *piVar1 = *piVar1 + 0x10;
        }
        else if (cVar3 == 'f') {
          puVar2 = (undefined8 *)(iVar7 + 8);
          iVar4 = *param_1;
          puVar6 = *(undefined8 **)(iVar4 + 8);
          iVar7 = iVar7 + 8;
          *puVar6 = *puVar2;
          iVar8 = iVar8 + 8;
          *(undefined4 *)(puVar6 + 1) = 3;
          piVar1 = (int *)(iVar4 + 8);
          *piVar1 = *piVar1 + 0x10;
        }
        else {
          if (cVar3 == 's') {
            puVar9 = *(undefined **)(iVar8 + 4);
          }
          else {
            if (cVar3 != 'w') goto LAB_006f4db2;
            WideCharToMultiByte(0,0,*(LPCWSTR *)(iVar8 + 4),-1,&DAT_00fe69d0,0x400,(LPCSTR)0x0,
                                (LPBOOL)0x0);
            puVar9 = &DAT_00fe69d0;
          }
          iVar8 = iVar8 + 4;
          iVar7 = iVar7 + 4;
          FUN_006f5510(puVar9);
        }
LAB_006f4db2:
        param_2 = param_2 + 1;
      }
      in_EDX = in_EDX + 1;
    } while (*in_EDX != '\0');
  }
  return param_2;
}

