
void FUN_0072e9a0(FILE *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = param_2;
  if (0 < param_2) {
    do {
      _fprintf(param_1,"    ");
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  piVar2 = (int *)(in_ECX + 0x20);
  piVar1 = piVar2;
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    piVar1 = (int *)*piVar2;
  }
  _fprintf(param_1,"<%s",piVar1);
  piVar1 = *(int **)(in_ECX + 0x94);
  if (piVar1 != (int *)(in_ECX + 0x44)) {
    do {
      if (piVar1 == (int *)0x0) break;
      _fprintf(param_1," ");
      (**(code **)(*piVar1 + 4))(param_1,param_2);
      piVar1 = (int *)piVar1[0x14];
    } while ((piVar1[0x10] != 0) || (piVar1[9] != 0));
  }
  piVar1 = *(int **)(in_ECX + 0x18);
  if (piVar1 == (int *)0x0) {
    _fprintf(param_1," />");
    return;
  }
  if ((piVar1 == *(int **)(in_ECX + 0x1c)) && (iVar3 = (**(code **)(*piVar1 + 0x2c))(), iVar3 != 0))
  {
    _fprintf(param_1,">");
    (**(code **)(**(int **)(in_ECX + 0x18) + 4))(param_1,param_2 + 1);
  }
  else {
    _fprintf(param_1,">");
    piVar1 = *(int **)(in_ECX + 0x18);
    if (piVar1 != (int *)0x0) {
      do {
        iVar3 = (**(code **)(*piVar1 + 0x2c))();
        if (iVar3 == 0) {
          _fprintf(param_1,"\n");
        }
        (**(code **)(*piVar1 + 4))(param_1,param_2 + 1);
        piVar1 = (int *)piVar1[0x10];
      } while (piVar1 != (int *)0x0);
    }
    _fprintf(param_1,"\n");
    if (0 < param_2) {
      do {
        _fprintf(param_1,"    ");
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    piVar2 = (int *)*piVar2;
  }
  _fprintf(param_1,"</%s>",piVar2);
  return;
}

