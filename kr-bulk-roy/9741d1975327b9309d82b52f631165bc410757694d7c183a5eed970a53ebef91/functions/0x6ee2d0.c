
void FUN_006ee2d0(FILE *param_1)

{
  undefined4 *puVar1;
  FILE *_File;
  undefined4 *puVar2;
  
  _File = param_1;
  _fread(&param_1,4,1,param_1);
  puVar1 = DAT_00fb905c;
  for (puVar2 = DAT_00fb9058; puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 8))(param_1,_File);
  }
  _fclose(_File);
  return;
}

