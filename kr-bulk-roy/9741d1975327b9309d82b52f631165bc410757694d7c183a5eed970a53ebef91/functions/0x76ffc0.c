
void FUN_0076ffc0(LONG *param_1,LONG *param_2,LPCWSTR param_3,int param_4)

{
  HDC hdc;
  int in_ECX;
  tagSIZE local_c;
  
  if (*(int *)(in_ECX + 4) != 0) {
    hdc = (HDC)(**(code **)(**(int **)(in_ECX + 4) + 0x20))(*(int **)(in_ECX + 4));
    GetTextExtentPoint32W(hdc,param_3,param_4,&local_c);
    *param_1 = local_c.cx;
    *param_2 = local_c.cy;
  }
  return;
}

