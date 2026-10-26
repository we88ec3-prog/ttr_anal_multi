
void FUN_00770000(LONG *param_1,LPCWSTR param_2,int param_3)

{
  HDC hdc;
  int in_ECX;
  tagSIZE local_c;
  
  if (*(int *)(in_ECX + 4) != 0) {
    hdc = (HDC)(**(code **)(**(int **)(in_ECX + 4) + 0x20))(*(int **)(in_ECX + 4));
    GetTextExtentPoint32W(hdc,param_2,param_3,&local_c);
    *param_1 = local_c.cx;
    param_1[1] = local_c.cy;
    return;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

