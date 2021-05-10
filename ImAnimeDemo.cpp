#include "ImAnime.h"

void windowPush() {
	static ImCounter<uint16_t> ctr1(ImCounterCond::REPEAT);
	static ImCounter<uint16_t> ctr2;

	uint16_t finish = 400;


	ImAnime::PushStyleColor(ctr1, finish, ImVec4(0.0f, 0.0f, 0.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.2f), ImAnimeType::LINEAR, ImGuiCol_WindowBg);

	ImAnime::PushStyleVar(ctr2, finish, 0.0f, 5.0f, ImAnimeType::LINEAR, ImGuiStyleVar_WindowBorderSize);

}

void resetAll(auto& counters) {
	if (ImGui::Button("Reset")) {
		for (auto& x : counters)
			x.reset();
	}
}

void windowPop() {
	ImAnime::PopStyleColor();
	ImAnime::PopStyleVar();
}

void header(const char* label, auto function) {
	if (ImGui::CollapsingHeader(label)) {
		function();
	}

	ImGui::Separator();
}

void basic() {

	static std::array<ImCounter<uint16_t>, 10> counters;
	uint16_t index = 0;

	resetAll(counters);

	if (ImGui::BeginTable("state", 3)) {

		ImGui::TableNextColumn();

		ImAnime::PushStyleColor
		(
			counters[index++],
			60,
			ImVec4(0.0f, 1.0f, 0.5f, 0.0f),
			ImVec4(0.0f, 1.0f, 0.5f, 1.0f),
			ImAnimeType::LINEAR,
			ImGuiCol_Text
		);
		ImGui::Text("Once");
		ImGui::PopStyleColor();

		ImGui::TableNextColumn();

		ImAnime::PushStyleColor
		(
			counters[index++],
			60,
			ImVec4(0.0f, 1.0f, 0.5f, 0.0f),
			ImVec4(0.0f, 1.0f, 0.5f, 1.0f),
			ImAnimeType::LINEAR,
			ImGuiCol_Text
		);
		if (ImGui::Button("Every Time"))
			counters[index - 1].reset();
		ImGui::PopStyleColor();

		ImGui::TableNextColumn();

		counters[index] |= ImCounterCond::REPEAT;
		ImAnime::PushStyleColor
		(
			counters[index++],
			60,
			ImVec4(0.0f, 1.0f, 0.5f, 0.0f),
			ImVec4(0.0f, 1.0f, 0.5f, 1.0f),
			ImAnimeType::LINEAR,
			ImGuiCol_Text
		);
		ImGui::Text("Repeat");
		ImGui::PopStyleColor();


		ImGui::TableNextColumn();


		counters[index] |= ImCounterCond::REVERSE;
		ImAnime::PushStyleColor
		(
			counters[index++],
			60,
			ImVec4(0.0f, 1.0f, 0.5f, 0.0f),
			ImVec4(0.0f, 1.0f, 0.5f, 1.0f),
			ImAnimeType::LINEAR,
			ImGuiCol_Text
		);
		ImGui::Text("Reverse");
		ImGui::PopStyleColor();


		ImGui::TableNextColumn();


		counters[index] |= ImCounterCond::REVERSE | ImCounterCond::REPEAT;
		ImAnime::PushStyleColor
		(
			counters[index++],
			60,
			ImVec4(0.0f, 1.0f, 0.5f, 0.0f),
			ImVec4(0.0f, 1.0f, 0.5f, 1.0f),
			ImAnimeType::LINEAR,
			ImGuiCol_Text
		);
		ImGui::Text("Reverse Repeat");
		ImGui::PopStyleColor();


		ImGui::TableNextColumn();


		counters[index] |= ImCounterCond::REPEAT;
		ImAnime::PushStyleColor
		(
			counters[index++],
			60,
			ImVec4(0.0f, 1.0f, 0.5f, 0.0f),
			ImVec4(0.0f, 1.0f, 0.5f, 1.0f),
			ImAnimeType::LINEAR,
			ImGuiCol_Text
		);
		if (ImGui::Button("Pause")) {
			counters[index - 1] ^= ImCounterCond::PAUSE;
		}
		ImGui::PopStyleColor();


		ImGui::EndTable();
	}

}

void sample1() {
	static std::array<ImCounter<ImAnimeTime>, 8> counters;
	uint16_t index = 0;

	resetAll(counters);

	ImGui::Separator();


	auto f = [&](uint16_t index, const char* name, float time) {
		ImAnime::PushStyleColor
		(
			counters[index],
			time,
			ImVec4(0.0f, 1.0f, 0.5f, 0.0f),
			ImVec4(0.0f, 1.0f, 0.5f, 1.0f),
			ImAnimeType::LINEAR,
			ImGuiCol_Text
		);
		ImGui::Text(name);
		ImGui::PopStyleColor();
	};

	static const char* names[] = {
		"0.5(s)",
		"1.0(s)",
		"1.5(s)",
		"2.0(s)",
		"2.5(s)",
		"3.0(s)",
		"3.5(s)",
		"4.0(s)"
	};

	static const float times[] = {
		0.5f,
		1.0f,
		1.5f,
		2.0f,
		2.5f,
		3.0f,
		3.5f,
		4.0f
	};

	for (uint16_t i = 0; auto & x : names) {
		f(i, x, times[i]);
		i++;
	}
}

void compare() {
	
	ImGui::BulletText("ImCounter<unsigned int>");
	
	static ImCounter<unsigned int> ctr1(ImCounterCond::REPEAT);
	static ImCounter<unsigned int> ctr2(ImCounterCond::REPEAT);

	static double time1 = 0.0f, time2 = 0.0f;


	//time1
	std::chrono::system_clock::time_point  start, end;
	start = std::chrono::system_clock::now();

	ImAnime::Dummy(ctr1, 400u, ImVec2(0.0f, 0.0f), ImVec2(100.0f, 0.0f));

	end = std::chrono::system_clock::now();  
	time1 += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); 

	ImGui::SameLine();
	ImGui::Text("Dynamic Time: %.f (microseconds)", time1);



	//time2
	start = std::chrono::system_clock::now();

	ImAnimeS::Dummy<ImAnimeVec2(0.0f, 0.0f), ImAnimeVec2(100.0f, 0.0f), 400u>::AnimeS(ctr2);

	end = std::chrono::system_clock::now();
	time2 += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	ImGui::SameLine();
	ImGui::Text("Static Time: %.f (microseconds)", time2);

	ImGui::Separator();



	ImGui::BulletText("ImCounter<ImAnimeTime>");



	static ImCounter<ImAnimeTime> ctr3(ImCounterCond::REPEAT);
	static ImCounter<ImAnimeTime> ctr4(ImCounterCond::REPEAT);

	static double time3 = 0.0f, time4 = 0.0f;

	//time3
	start = std::chrono::system_clock::now();

	ImAnime::Dummy(ctr3, 10.0f, ImVec2(0.0f, 0.0f), ImVec2(100.0f, 0.0f));

	end = std::chrono::system_clock::now();
	time3 += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	ImGui::SameLine();
	ImGui::Text("Dynamic Time: %.f (microseconds)", time3);



	//time4
	start = std::chrono::system_clock::now();
	
	ImAnimeS::Dummy<ImAnimeVec2(0.0f, 0.0f), ImAnimeVec2(100.0f, 0.0f), 10.0f>::AnimeS(ctr4);
	
	end = std::chrono::system_clock::now();
	time4 += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	
	ImGui::SameLine();
	ImGui::Text("Static Time: %.f (microseconds)", time4);
}

void ImAnime::ShowDemoWindow() {
	windowPush();

	ImGui::Begin("ImAnimeDemoWindow");
	windowPop();

	header("Basic", basic);

	header("Sample1", sample1);

	header("Compare Processing Time", compare);

	ImGui::End();
}