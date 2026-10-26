
void FUN_00770050(LPINT param_1,int param_2,LPCWSTR param_3,int param_4)

{
  HDC hdc;
  int in_ECX;
  tagSIZE local_c;
  
  if (*(int *)(in_ECX + 4) != 0) {
    hdc = (HDC)(**(code **)(**(int **)(in_ECX + 4) + 0x20))(*(int **)(in_ECX + 4));
    GetTextExtentExPointW(hdc,param_3,param_4,param_2,param_1,(LPINT)0x0,&local_c);
  }
  return;
}

