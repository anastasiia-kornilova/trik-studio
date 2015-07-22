/* Copyright 2007-2015 QReal Research Group
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#include "setBackgroundGenerator.h"

#include <generatorBase/generatorCustomizer.h>
#include "src/converters/backgroundColorConverter.h"

using namespace trik::simple;
using namespace trik::converters;
using namespace generatorBase::simple;

SetBackgroundGenerator::SetBackgroundGenerator(const qrRepo::RepoApi &repo
		, generatorBase::GeneratorCustomizer &customizer
		, const qReal::Id &id
		, QObject *parent)
	: BindingGenerator(repo, customizer, id
			, "drawing/setBackground.t"
			, { Binding::createConverting("@@COLOR@@", "Color"
						, new BackgroundColorConverter(customizer.factory()->pathsToTemplates()))
				, Binding::createConverting("@@REDRAW@@", "Redraw"
						, customizer.factory()->boolPropertyConverter(id, "Redraw", false)) }
			, parent)
{
}
