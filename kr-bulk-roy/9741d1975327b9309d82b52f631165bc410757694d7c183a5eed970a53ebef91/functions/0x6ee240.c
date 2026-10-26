
void FUN_006ee240(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  FILE *_File;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_8;
  
  _File = _fopen("Tartaros.cfg","wbc");
  if (_File != (FILE *)0x0) {
    local_8 = (**(code **)*param_1)();
    _fwrite(&local_8,4,1,_File);
    puVar1 = (undefined4 *)param_1[3];
    for (puVar4 = (undefined4 *)param_1[2]; puVar4 != puVar1; puVar4 = puVar4 + 1) {
      iVar2 = *(int *)*puVar4;
      uVar3 = (**(code **)*param_1)(_File);
      (**(code **)(iVar2 + 4))(uVar3);
    }
    _fclose(_File);
  }
  return;
}

